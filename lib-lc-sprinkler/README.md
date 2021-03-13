# lib-lc-csprinkler

This is the abstracted application layer for the sprinkler controller

`app.hpp` is the high level application class that runs the controller, 
recieves input and produces output.

The `app::App` class inherits from `widget::Widget` in order to be able to Draw itself
and all its children as defined in `App::init`.

Calling `App::Tick` in the event loop will Render and process the app.

Implementors (SDL, esp-idf) are responsible for subclassing `gfx::Display` to provide a target
for rendering the app and widget hierarchy.

Implementors (SDL, esp-idf) are responsible for binding the app and calling the 
`App::HandleInputEvent` method as required to pass input events into the widget hierarchy.
Events will be passes down the tree to all widgets who can individually decide what to do with them.