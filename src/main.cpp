#include <App.hpp>

#include <Player.hpp>

#include <MainView.hpp>

#include <Utils.hpp>

#include <AddArtist.hpp>

int main() {
    App& app = App::Get();

    app.gui.AddWindow<Player>();

    app.gui.AddWindow<MainView>();

    app.Run();

    return 0;
}