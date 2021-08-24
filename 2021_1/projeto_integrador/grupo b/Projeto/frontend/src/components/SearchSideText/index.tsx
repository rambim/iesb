import styles from './styles.module.scss';
import badge from '../../images/badge.svg';

export function SearchSideText() {
    return (
        <>
            <h1>LEITOS<span>.</span>BR</h1>
            <div className={styles.boxInside}>
                <p><strong><span>#</span>FICAEMCASA</strong></p>
                <div className={styles.description}>
                    <img src={badge} alt="git"></img>
                    <span className={styles.loginText}>Digite seu estado e veja o <span>número de leitos de UTI</span> ocupados.</span>
                </div>
            </div>
        </>
    );
}