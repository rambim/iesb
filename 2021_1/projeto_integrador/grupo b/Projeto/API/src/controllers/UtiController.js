const knex = require('../database');

module.exports = {
    async listagem(req, res) {
        const { sigla } = req.params;
        const UTIS = await knex('utis');

        if (sigla) {
            const utisFiltradas = UTIS.find((uti) => {
                if (uti.sigla === sigla) {
                    return uti;
                }
            });
            if (utisFiltradas) {
                return res.json(utisFiltradas);
            }
            return res.status(404).send();
        }
        return res.status(404).send();
    },

    async create(req, res, next) {
        const { nome, sigla, casos, obitos, vacinados, ocupacao } = req.body;
        try {
            await knex('utis').insert({
                nome,
                sigla,
                casos,
                obitos,
                vacinados,
                ocupacao
            });

            return res.status(201).send();
        } catch (err) {
            next(err);
        }
    },

    async update(req, res, next) {
        const { sigla } = req.params;
        const { recuperados, ocupacao, casos, obitos, vacinados } = req.body;

        try {
            await knex('utis').update({ recuperados, ocupacao, casos, obitos, vacinados }).where({ sigla });
            res.status(201).send();
        } catch (err) {
            next(err);
        }
    }
}