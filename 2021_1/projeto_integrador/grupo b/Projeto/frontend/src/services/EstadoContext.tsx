import { ReactNode, useState } from 'react';
import { createContext, useContext } from 'react';


interface EstadoContextProps {
    nome: string;
    setNome: (nome: string) => void;
}

export const EstadoContext = createContext<EstadoContextProps>({} as EstadoContextProps);

export function EstadoProvider({ children }: { children: ReactNode }) {
    const [nome, setNome] = useState('');

    return (
        <EstadoContext.Provider value={{ nome, setNome }}>
            {children}
        </EstadoContext.Provider >
    );
}