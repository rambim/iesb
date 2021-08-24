import { Wrapper } from './components/Wrapper';
import './global.module.scss';
import { EstadoProvider } from './services/EstadoContext';

function App() {
  return (
    <EstadoProvider>
      <Wrapper />
    </EstadoProvider>
  );
}

export default App;
