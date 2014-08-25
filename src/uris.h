/*
 LV2 URIs
*/

#ifndef WHYSYNTH_URIS_H
#define WHYSYNTH_URIS_H

#include "lv2/lv2plug.in/ns/ext/midi/midi.h"
#include "lv2/lv2plug.in/ns/ext/urid/urid.h"

#define WHYSYNTH_URI "http://smbolton.com/whysynth"

typedef struct {
    LV2_URID midi_Event;
} y_URIs_t;

static inline void
map_whysynth_uris(LV2_URID_Map* map, y_URIs_t* uris)
{
    uris->midi_Event         = map->map(map->handle, LV2_MIDI__MidiEvent);
}

#endif  /* WHYSYNTH_URIS_H */
