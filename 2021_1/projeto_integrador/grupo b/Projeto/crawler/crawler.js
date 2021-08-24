const puppeteer = require('puppeteer');
const axios = require('axios');

async function pega_dados() {
  const browser = await puppeteer.launch();
  const page = await browser.newPage();
  await page.goto('https://datastudio.google.com/embed/reporting/2f2537fa-ac23-4f08-8741-794cdbedca03/page/ROITB', {
    waitUntil: 'networkidle0',
  });

  var dados_total;

  let dados1 = await page.evaluate(() => {
    const dados_raw = [];

    for (let i = 0; i < 189; i++) {
      let sigla = document.querySelectorAll('.cell')[i].innerText;
      let ocupacao = document.querySelectorAll('.cell')[i += 4].innerText;
      let ultimatt = document.querySelectorAll('.cell')[i += 1].innerText;
      let fonte = document.querySelectorAll('.cell')[i += 1].innerText;

      dados_raw.push({
        sigla,
        ocupacao,
        ultimatt,
        fonte
      });
    }

    return dados_raw;
  });

  dados_total = dados1;

  await page.goto('https://datastudio.google.com/embed/reporting/2f2537fa-ac23-4f08-8741-794cdbedca03/page/CPFTB%27,%7B', {
    waitUntil: 'networkidle0',
  });

  let dados2 = await page.evaluate(() => {
    const dados_raw = [];

    for (let i = 0; i <= 349; i++) {
      let sigla = document.querySelectorAll('.cell')[i].innerText
      let total_casos = document.querySelectorAll('.cell')[i += 1].innerText;
      let total_obitos = document.querySelectorAll('.cell')[i += 1].innerText;
      let recuperados = document.querySelectorAll('.cell')[i += 5].innerText;
      let pop_vac = document.querySelectorAll('.cell')[i += 4].innerText;
      i += 1;

      dados_raw.push({
        sigla,
        total_casos,
        total_obitos,
        recuperados,
        pop_vac
      });
    }

    return dados_raw;
  });


  for (let i = 0; i < 27; i++) {
    for (let j = 0; j <= 26; j++) {

      if (dados_total[i].sigla === dados2[j].sigla) {

        dados_total[i].casos = dados2[j].total_casos;
        dados_total[i].obitos = dados2[j].total_obitos;
        dados_total[i].recuperados = dados2[j].recuperados;
        dados_total[i].vacinados = dados2[j].pop_vac;
      }
    }

  }

  dados_total.forEach(estado => {
    axios.put(`http://localhost:3333/leitos/${estado.sigla}`, estado);
  });

  await browser.close();
}
pega_dados();