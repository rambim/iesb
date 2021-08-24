exports.up = function (knex) {
    return knex.schema.createTable('utis', function (table) {
        table.text('nome');
        table.text('sigla');
        table.text('casos');
        table.text('obitos');
        table.text('vacinados');
        table.text('ocupacao');
    });
};

exports.down = function (knex) {
    return knex.schema.dropTable('utis');
};
