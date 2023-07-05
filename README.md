# Node.JS Event Emiter In C

Node.JS-like Event Emiter

## Usage

```c
#include "event.h"

void hello(void* arg) { printf("%s %s\n", "hello", (char*)arg); }
void hi(void* arg) { printf("%s %s\n", "hi", (char*)arg); }

int main(void) {
  event_emiter_t* event_emiter = event_emiter_new();

  event_emitter_on(event_emiter, "hello", hello);

  event_emitter_emit(event_emiter, "hello", "world");
  event_emitter_emit(event_emiter, "hello", "world");

  event_emitter_once(event_emiter, "hi", hi);
  event_emitter_emit(event_emiter, "hi", "myfreax");
  event_emitter_emit(event_emiter, "hi", "myfreax");  // invalid

  event_emiter_destroy(event_emiter);
}
```

## Installation

```
clib install myfreax/event-emiter
```
