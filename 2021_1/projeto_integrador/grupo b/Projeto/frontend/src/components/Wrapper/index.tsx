import { SearchSide } from '../SearchSide/index';
import styles from './styles.module.scss';
import medicos from '../../images/medics.svg';
import { useEffect, useState, useContext } from 'react';
import { SideBarMenu } from '../SideBarMap';
import { MapBox } from '../MapBox';
import { EstadoContext } from '../../services/EstadoContext';
import { estados_info } from './estados';

export function Wrapper() {

    const { nome } = useContext(EstadoContext);
    const [visible, setvisible] = useState(true);
    const teste = estados_info.find((estado) => {
        if (estado.nome === nome) {
            return true;
        }
        return false;
    });

    useEffect(() => {
        if (teste) {
            setvisible(!teste);
        }
    }, [nome]);

    return (
        <>
            {
                visible ? (
                    <div className={styles.app}>
                        <div className={styles.main}>
                            <div className={styles.image}>
                                <img src={medicos} alt="" />
                            </div>
                            <div>
                                <SearchSide />
                            </div>
                        </div>
                    </div>
                ) : (
                    <>
                        <SideBarMenu />
                        <MapBox />
                    </>
                )
            }
        </>
    );
}