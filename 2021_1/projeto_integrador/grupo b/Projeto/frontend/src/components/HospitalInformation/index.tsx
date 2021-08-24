import styles from './styles.module.scss';

interface HospitalProps {
    lat: number;
    lng: number;
    name: string;
}

export function HospitalInformation(props: HospitalProps) {
    return (
        <>
            <div className={styles.Container}>
                <p>{props.name}</p>
            </div>
        </>
    );
}