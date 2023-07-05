#include "event.h"

#include <string.h>

event_emiter_t* event_emiter_new() {
  event_emiter_t* event_emiter = malloc(sizeof(event_emiter_t));
  event_emiter->events = list_new();
  event_emiter->events->free = free;
  return event_emiter;
}

void event_emitter_once(event_emiter_t* self, char* name, void* callback) {
  event_emitter_listen(self, name, callback, true);
}

void event_emitter_on(event_emiter_t* self, char* name, void* callback) {
  event_emitter_listen(self, name, callback, false);
}

void event_emitter_listen(event_emiter_t* self, char* name, void* callback,
                          bool once) {
  event_t* event = malloc(sizeof(event_t));
  event->callback = callback;
  event->name = name;
  event->once = once;
  list_rpush(self->events, list_node_new(event));
}

void event_emitter_emit(event_emiter_t* self, char* name, void* arg) {
  list_iterator_t* it = list_iterator_new(self->events, LIST_HEAD);
  list_node_t* node;
  while ((node = list_iterator_next(it))) {
    event_t* event = node->val;
    if (strcmp(event->name, name) == 0) {
      event->callback(arg);
      if (event->once) {
        list_remove(self->events, node);
      }
    }
  }
  free(it);
}

void event_emiter_destroy(event_emiter_t* self) {
  list_destroy(self->events);
  free(self);
}