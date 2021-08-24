import { useContext, useEffect, useState } from 'react';
import { EstadoContext } from '../../services/EstadoContext';
import { BoxInfoUti } from '../BoxInfoUti';
import { InformationBox } from '../InformationBox';
import { WhenGoHospital } from '../WhenGoHospital';
import styles from './styles.module.scss';
import { estados_info } from './estados';
import axios from 'axios';

export function SideBarMenu() {
    const [modalIsOpen, setIsOpen] = useState(false);
    const [apiRequest, setApiRequest]: any = useState({});
    const { nome } = useContext(EstadoContext);

    const nomeFiltrado = estados_info.find((estado) => {
        if (estado.nome === nome) {
            return estado;
        }
    });

    useEffect(() => {
        axios.get(`http://localhost:3333/leitos/${nomeFiltrado?.UF}`).then((res) => {
            res.data.ocupacao.replace(/[%]/g, "");
            res.data.vacinados.replace(/[%]/g, "");
            setApiRequest(res.data);
        });
    });

    function openModal() {
        setIsOpen(true);
    }
    function closeModal() {
        setIsOpen(false);
    }

    return (
        <div className={styles.sideBar}>
            <div className={styles.nomeEstados}>
                <h2>{nomeFiltrado?.nome} - {nomeFiltrado?.UF}</h2>
            </div>
            <BoxInfoUti perCent={apiRequest.ocupacao} tittle="Leitos de UTI" description="nivel de ocupação das UTIS do estado do Distrito Federal." />
            <BoxInfoUti perCent={apiRequest.vacinados} tittle="Vacinados" description="o número de vacinados no estado do Distrito Federal." />
            <InformationBox dados={apiRequest} />
            <WhenGoHospital openModal={openModal} closeModal={closeModal} modalIsOpen={modalIsOpen} />
        </div>
    );
}