import { MapContainer, Marker, Popup, TileLayer } from "react-leaflet";
import { useContext, useState } from 'react';
import L from 'leaflet';
import mapmarker from '../../images/mapmarker.svg';
import { places } from './teste';
import Modal from 'react-modal';
import { estados_info } from '../SideBarMap/estados';

import styles from './styles.module.scss';
import { HospitalInformation } from "../HospitalInformation";
import { EstadoContext } from "../../services/EstadoContext";

const markerIcon = new L.Icon({
    iconUrl: `${mapmarker}`,
    iconSize: [35, 35],
});

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

interface HospitalProps {
    lat: number;
    lng: number;
    name: string;
}

export function MapBox() {
    const { nome } = useContext(EstadoContext);

    const filtro = estados_info.find((estado) => {
        if (estado.nome === nome) {
            return estado;
        }
    })

    const [center, setCenter] = useState<any>({ lat: filtro?.lat, lng: filtro?.lng });
    const ZOOM_LEVEL = 13;

    const [modalIsOpen, setIsOpen] = useState(false);
    const [estado, setEstado] = useState<HospitalProps>({} as HospitalProps);

    function closeModal() {
        setIsOpen(false);
    }

    return (
        <>
            <div className={styles.map}>
                <MapContainer center={center} zoom={ZOOM_LEVEL} style={{ width: '100%', height: '100%' }} >
                    <TileLayer url='https://api.mapbox.com/styles/v1/mapbox/light-v10/tiles/{z}/{x}/{y}?access_token=pk.eyJ1IjoiaG9iYmF0bWFuIiwiYSI6ImNrZzgzZ2JzbDBkYnEycW15NTV3bzBsbGgifQ.33I4ABckf8ciQZ2NCd1MEw'></TileLayer>
                    {places.map((hospital) => {
                        return (
                            <Marker position={[hospital.lat, hospital.lng]} icon={markerIcon}>
                                <Popup className={styles.popupMarker}>
                                    <p>{hospital.name}</p>
                                </Popup>
                            </Marker>
                        );
                    })}
                </MapContainer>
            </div>
            <Modal
                isOpen={modalIsOpen}
                onRequestClose={closeModal}
                style={customStyles}
            >
                <HospitalInformation {...estado} />
            </Modal>
        </>
    );
}