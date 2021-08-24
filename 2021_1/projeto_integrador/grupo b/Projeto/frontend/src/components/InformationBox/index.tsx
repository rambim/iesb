import styles from './styles.module.scss';
import Skull from '../../images/skull.svg';
import Sick from '../../images/sick.svg';
import Health from '../../images/health.svg';


export function InformationBox(props: any) {
    return (
        <div className={styles.casesNumber}>
            <h2>Dados</h2>
            <span className={styles.numMortos}><img src={Skull} alt="Caveira" />Número de mortos: <span>{props.dados.obitos}</span></span>
            <span className={styles.numDoentes}><img src={Sick} alt="Doente" />Número de casos: <span>{props.dados.casos}</span></span>
            <span className={styles.numSaudaveis}><img src={Health} alt="Saude" />Número de recuperados: <span>{props.dados.recuperados}</span></span>
        </div>
    );
}