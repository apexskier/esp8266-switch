void routes_setup() {
    server.on("/", routes_root);
    server.onNotFound(routes_404);
    server.begin();
    Serial.println("HTTP server started");
}

void routes_loop() {
    server.handleClient();
}

void routes_root() {
    String message;
    uint8_t num_args;
    switch (server.method()) {
    case HTTP_GET:
        message += "{\"open\":";
        message += switch_open ? "true" : "false";
        message += "}";
        server.send(200, "application/json", message);
        break;
    case HTTP_POST:
        num_args = server.args();
        if (num_args > 0) {
            String val; // larger than valid
            for (uint8_t arg_i = 0; arg_i < num_args; arg_i++) {
                String arg_name = server.argName(arg_i);
                if (arg_name == "open") {
                    val = server.arg(arg_i);
                } else if (arg_name == "plain") {
                    // ignore TODO: find out why this exists
                } else {
                    server.send(400);
                    return;
                }
            }
            if (val == "true") {
                switch_open = true;
                server.send(202);
                return;
            } else if (val == "false") {
                switch_open = false;
                server.send(202);
                return;
            }
        }
        server.send(400);
        return;
    default:
        server.send(405);
        break;
    }
}

void routes_404() {
    server.send(404);
}
