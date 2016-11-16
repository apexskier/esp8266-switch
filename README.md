Basic wifi controlled switch based on an ESP8266 and Arduino.

## HTTP API

### GET `/`

Returns JSON describing switch status.

```json
{
    "open": true
}
```

### POST `/?open=[true|false]`

HTTP status indicates success or failure.

