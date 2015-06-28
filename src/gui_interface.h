/* WhySynth DSSI software synthesizer GUI
 *
 * Copyright (C) 2004-2008, 2010, 2012 Sean Bolton and others.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 */

#ifndef _GUI_INTERFACE_H
#define _GUI_INTERFACE_H

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#if LV2_ENABLED
#   include "lv2/lv2plug.in/ns/extensions/ui/ui.h"
#endif

extern GtkWidget *main_window;
extern GtkObject *main_test_note_key_adj;
extern GtkObject *main_test_note_velocity_adj;

extern GtkWidget *notebook;

extern GtkWidget *patches_clist;

extern GtkWidget *about_window;
extern GtkWidget *about_label;

extern GtkWidget *open_file_chooser;
extern GtkObject *open_file_position_spin_adj;
extern GtkWidget *open_file_position_name_label;

extern GtkWidget *save_file_chooser;
extern GtkObject *save_file_start_spin_adj;
extern GtkWidget *save_file_start_name;
extern GtkObject *save_file_end_spin_adj;
extern GtkWidget *save_file_end_name;
#ifdef DEVELOPER
extern GtkWidget *save_file_c_mode_button;
#endif /* DEVELOPER */

extern GtkWidget *import_file_chooser;
extern GtkObject *import_file_position_spin_adj;
extern GtkWidget *import_file_position_name_label;
extern GtkWidget *import_file_position_dual_button;

extern GtkWidget *notice_window;
extern GtkWidget *notice_label_1;
extern GtkWidget *notice_label_2;

extern GtkWidget *edit_window;
extern GtkObject *edit_test_note_key_adj;
extern GtkObject *edit_test_note_velocity_adj;
extern GtkWidget *edit_test_note_button;
extern GtkWidget *edit_test_note_toggle;

extern GtkWidget *edit_save_position_window;
extern GtkObject *edit_save_position_spin_adj;
extern GtkWidget *edit_save_position_name_label;

extern GtkWidget *name_entry;
extern GtkWidget *comment_entry;

extern GtkObject *tuning_adj;
extern GtkObject *polyphony_adj;
extern GtkWidget *monophonic_option_menu;
extern GtkWidget *glide_option_menu;
extern GtkWidget *program_cancel_button;

struct voice_widgets {
    GtkWidget *widget;    /* knob, spin button, combo box, etc. */
    GtkObject *adjustment;
    GtkWidget *top_label;
    GtkWidget *label1;    /* knob lower left label, detent value label */
    GtkWidget *label2;    /* knob lower right label */
    int        last_mode;
};

struct y_osc_modes_t {
    char *name;
    int   priority;
    int   id;
    char *mparam1_top_label;
    char *mparam1_left_label;
    char *mparam1_right_label;
    char *mparam2_top_label;
    char *mparam2_left_label;
    char *mparam2_right_label;
    char *mmod_src_top_label;
    char *mmod_amt_top_label;
};

extern struct y_osc_modes_t y_osc_modes[];

struct y_vcf_modes_t {
    char *name;
    int   priority;
    int   id;
    char *qres_top_label;
    char *mparam_top_label;
};

extern struct y_vcf_modes_t y_vcf_modes[];

struct y_effect_modes_t {
    char *name;
    int   priority;
    int   id;
    char *mparam1_top_label;
    char *mparam2_top_label;
    char *mparam3_top_label;
    char *mparam4_top_label;
    char *mparam5_top_label;
    char *mparam6_top_label;
};

extern struct y_effect_modes_t y_effect_modes[];

extern GQuark combomodel_id_to_path_quark;

extern GtkTreeStore *combomodel[];
extern GQuark combo_value_quark;
extern GQuark combo_combomodel_type_quark;

extern enum y_plugin_mode plugin_mode;

// Data needed by UI callback functions.
//  - index corresponds to #defines in whysynth_ports.h
//  - lv2_write_function points to the function used to
//    values back to the LV2 host
//  - voice_widgets points to the array of voice_widget
//    structs describing the UI elements.
struct y_ui_callback_data_t {
    int index;
#if LV2_ENABLED
    LV2UI_Write_Function lv2_write_function;
    LV2UI_Controller lv2_controller;
#endif
    struct voice_widgets* voice_widgets;
};

void create_windows(const char *instance_tag, struct y_ui_callback_data_t* callback_data);
void create_edit_window (const char *tag, struct y_ui_callback_data_t* callback_data);
#if LV2_ENABLED
void set_lv2_write_function(struct y_ui_callback_data_t* callback_data, LV2UI_Write_Function function);
void set_lv2_controller(struct y_ui_callback_data_t* callback_data, LV2UI_Controller controller);
#endif


#endif /* _GUI_INTERFACE_H */
