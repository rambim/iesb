import Modal from 'react-modal';
import { WhenGoHospitalContent } from '../WhenGoHospitalContent';

import styles from './styles.module.scss';

interface ModalProps {
    openModal: () => void;
    closeModal: () => void;
    modalIsOpen: boolean;
}

const customStyles = {
    content: {
        top: '50%',
        left: '50%',
        right: 'auto',
        bottom: 'auto',
        marginRight: '-50%',
        transform: 'translate(-33%, -50%)'
    }
};


export function WhenGoHospital(props: ModalProps) {

    return (
        <>
            <div className={styles.infos}>
                <div>
                    <span className={styles.textoInfo}>Quando ir ao hospital ?</span>
                    <span className={styles.textoInfoDescript}>Devido ao elevado número de UTIs ocupadas é importante saber quando ir ao hospital. Clique no botão para entender quando ir.</span>
                </div>
                <button onClick={() => { props.openModal() }}>Aqui</button>
            </div>


            <Modal
                isOpen={props.modalIsOpen}
                onRequestClose={props.closeModal}
                style={customStyles}
            >

                <WhenGoHospitalContent propriedade={props} />
            </Modal>
        </>
    );
}