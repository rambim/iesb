const express = require('express');
const UtiController = require('./controllers/UtiController');
const routes = express.Router();
const cors = require('cors');

var corsOptions = {
    origin: 'http://localhost:3000',
    optionsSuccessStatus: 200
};

routes.use(cors(corsOptions));

routes.get('/leitos/:sigla', UtiController.listagem);
routes.post('/leitos', UtiController.create);
routes.put('/leitos/:sigla', UtiController.update);

module.exports = routes;