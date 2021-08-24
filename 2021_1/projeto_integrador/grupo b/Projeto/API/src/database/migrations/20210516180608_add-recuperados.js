exports.up = function (knex) {
    return knex.schema.alterTable('utis', function (table) {
        table.text('recuperados');
    });
};

exports.down = function (knex) {
    return knex.schema.alterTable('utis', function (table) {
        table.dropColumn('recuperados');
    });
};
