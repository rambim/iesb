import { useContext, useState } from 'react';
import { sugestion } from './sugestions';
import { SearchSideText } from '../SearchSideText/index';

import styles from './style.module.scss';
import arrow from '../../images/arrow.svg';
import { EstadoContext } from '../../services/EstadoContext';

let sugestions = sugestion;
let emptyArray: any[] = [];
let array: any[] = [];

export function SearchSide() {

    const [ativo, setAtivo] = useState(styles.autocomBox);
    const [texto, setTexto] = useState('');
    const { setNome } = useContext(EstadoContext);

    return (
        <div className={styles.seachSide}>
            <SearchSideText />
            <div className={styles.wrapper}>
                <input className={styles.barInput} type="text" placeholder="Digite aqui o seu estado" onChange={
                    (e) => {
                        setTexto(e.target.value);
                        if (e.target.value) {
                            emptyArray = sugestions.filter((data) => {
                                return data.toLocaleLowerCase().startsWith(e.target.value.toLocaleLowerCase());
                            });
                            array = emptyArray = emptyArray.map((data) => {
                                return data;
                            });
                            console.log(e.target.value);
                            setAtivo(styles.autocomBoxActive);
                        } else if (e.target.value === '') {
                            setAtivo(styles.autocomBox);
                        }
                    }

                } value={texto} />

                <div className={ativo}>
                    {
                        array.map((e) =>
                            <li onClick={() => { setTexto(e); setAtivo(styles.autocomBox); }}>{e}</li>
                        )
                    }
                </div>
            </div>
            <button type="button" className={styles.button} onClick={() => { setNome(texto) }}><img src={arrow} alt="" /></button>
        </div>
    );
}