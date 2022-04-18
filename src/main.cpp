#include <dpp/dpp.h>

std::string BOT_TOKEN;
dpp::snowflake GUILD_ID;

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [BOT_TOKEN] [GUILD_ID]", argv[0]);
    }
    BOT_TOKEN = argv[1];
    GUILD_ID = strtol(argv[2], nullptr, 10);

    dpp::cluster bot(BOT_TOKEN);

    bot.on_interaction_create([](const dpp::interaction_create_t &event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t &event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.guild_command_create(
                dpp::slashcommand("ping", "Ping pong!", bot.me.id), GUILD_ID);
        }
    });

    bot.start(false);
}
