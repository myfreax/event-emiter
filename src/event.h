#include <stdbool.h>

#include "list.h"

typedef struct {
  bool once;
  char* name;
  void (*callback)(void* args);
} event_t;

typedef struct {
  list_t* events;
} event_emiter_t;

event_emiter_t* event_emiter_new();
void event_emitter_on(event_emiter_t* self, char* event_name, void* callback);
void event_emitter_emit(event_emiter_t* self, char* event_name, void* arg);
void event_emiter_destroy(event_emiter_t* self);
void event_emitter_once(event_emiter_t* self, char* name, void* callback);
void event_emitter_listen(event_emiter_t* self, char* name, void* callback,
                          bool once);