import styles from './styles.module.scss';
import X from '../../images/X.svg';

interface ModalProps {
    openModal: () => void;
    closeModal: () => void;
    modalIsOpen: boolean;
}

interface GoHospitalProps {
    propriedade: ModalProps;
}

export function WhenGoHospitalContent(props: GoHospitalProps) {
    return (
        <div className={styles.modalStyle}>
            <div>
                <button onClick={props.propriedade.closeModal}><img src={X} alt="" /></button>
                <h1>COVID-19</h1>
                <p className={styles.subTittle}>O momento certo de ir ao hospital.</p>
                <br />
                <p>Assim como as expressões populares “Nem tanto, nem tão pouco", "Nem tanto ao mar, nem tanto à terra", não devemos sobrecarregar as emergências e aumentar a exposição ao ambiente hospitalar sem necessidade, nem esperar o agravamento, procurando atendimento somente numa fase tardia, mais difícil de ser tratada.</p>
                <br />
                <p>Cerca de 85% dos pacientes infectados pelo vírus da doença vão atravessar a fase I na primeira semana da infecção, sem sintomas ou com sintomas leves, chamados de síndrome gripal (febre, dor de garganta, dor de cabeça, perda do olfato e do paladar, dores no corpo, diarréia, enjôo, vômitos e indisposição, isolados ou em combinação). Nesta fase, o organismo pode produzir imunidade, eliminar o vírus e curar a infecção, sem grandes consequências. O atendimento médico-hospitalar será raramente necessário neste período. Somente nos casos de desidratação ou sintomas intensos sem melhora com medicação oral.</p>
                <br />
                <p>Em torno de 15% dos infectados vão evoluir para a fase II da doença, com comprometimento pulmonar, esses terão que se dirigir ao hospital para avaliação médica, exames laboratoriais e radiológicos e tratamento adequados hospitalizados.</p>
            </div>
            <div>
                <p>Mas como saber se o paciente está evoluindo para a cura espontânea ou caminhando para as fases mais graves da doença?</p>
                <ol>
                    <li><span>Fique em casa, isolado o mais possível dos seus contactantes domiciliares, tomando apenas medicamentos sintomáticos (para baixar a febre, tratar a dor e combater o enjôo, por exemplo);</span></li>
                    <li><span>De preferência, faça contato com o seu médico assistente para ir notificando o seu estado;</span></li>
                    <li><span>Atenção a partir do quinto dia do início dos sintomas para os sinais de alerta:</span>
                        <ul>
                            <li><span>Se a febre persiste, ou se havia passado e retornou;</span></li>
                            <li><span>Se surgiram dores no peito ou sensação de aperto ou desconforto ao respirar;</span></li>
                            <li><span>Se estava melhor e retornou com a sensação de cansaço</span></li>
                            <li><span>Se a oxigenação do sangue baixou de 94% (quando dispuser de oxímetro – um aparelho simples que mede a oxigenação quando acoplado à ponta do dedo)</span></li>
                        </ul>
                    </li>
                </ol>
            </div>
        </div>
    );
}