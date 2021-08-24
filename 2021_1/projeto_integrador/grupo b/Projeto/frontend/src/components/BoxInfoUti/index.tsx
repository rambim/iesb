import styles from './styles.module.scss';
import Info from '../../images/info.svg';
import './c-circular-progress.scss';

interface BoxInfoUtiProps {
    perCent: string;
    tittle: string;
    description: string;
}

export function BoxInfoUti(props: BoxInfoUtiProps) {
    return (
        <div className={styles.utiNumber}>
            <div className={styles.barQuantidade}>
                <span className={`c-circular-progress c-circular-progress--${parseInt(props.perCent)}`}></span>
            </div>
            <div className={styles.text}>
                <span className={styles.textoUTI}>{props.tittle}<img className={styles.info} src={Info} alt=''></img></span>
                <span className={styles.textoUTIDescript}>Aqui conseguimos ver o {props.description}</span>
            </div>
        </div >
    );
}