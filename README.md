Basic wifi controlled switch based on an ESP8266 and Arduino.

## HTTP API

### GET `/`

Returns JSON describing switch status.

```json
{
    open: boolean
}
```

### POST `/?open=[true|false]`

HTTP status indicates success or failure.

