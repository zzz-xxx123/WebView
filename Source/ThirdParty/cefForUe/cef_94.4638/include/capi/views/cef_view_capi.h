// Copyright (c) 2021 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=84b29a8dcdadffae5466ac16e7aafd80471a0abd$
//

#ifndef CEF_INCLUDE_CAPI_VIEWS_CEF_VIEW_CAPI_H_
#define CEF_INCLUDE_CAPI_VIEWS_CEF_VIEW_CAPI_H_
#pragma once

#include "include/capi/views/cef_view_delegate_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_browser_view_t;
struct _cef_button_t;
struct _cef_panel_t;
struct _cef_scroll_view_t;
struct _cef_textfield_t;
struct _cef_window_t;

///
// A View is a rectangle within the views View hierarchy. It is the base
// structure for all Views. All size and position values are in density
// independent pixels (DIP) unless otherwise indicated. Methods must be called
// on the browser process UI thread unless otherwise indicated.
///
typedef struct _cef_view_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Returns this View as a BrowserView or NULL if this is not a BrowserView.
  ///
  struct _cef_browser_view_t*(CEF_CALLBACK* as_browser_view)(
      struct _cef_view_t* self);

  ///
  // Returns this View as a Button or NULL if this is not a Button.
  ///
  struct _cef_button_t*(CEF_CALLBACK* as_button)(struct _cef_view_t* self);

  ///
  // Returns this View as a Panel or NULL if this is not a Panel.
  ///
  struct _cef_panel_t*(CEF_CALLBACK* as_panel)(struct _cef_view_t* self);

  ///
  // Returns this View as a ScrollView or NULL if this is not a ScrollView.
  ///
  struct _cef_scroll_view_t*(CEF_CALLBACK* as_scroll_view)(
      struct _cef_view_t* self);

  ///
  // Returns this View as a Textfield or NULL if this is not a Textfield.
  ///
  struct _cef_textfield_t*(CEF_CALLBACK* as_textfield)(
      struct _cef_view_t* self);

  ///
  // Returns the type of this View as a string. Used primarily for testing
  // purposes.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_type_string)(
      struct _cef_view_t* self);

  ///
  // Returns a string representation of this View which includes the type and
  // various type-specific identifying attributes. If |include_children| is true
  // (1) any child Views will also be included. Used primarily for testing
  // purposes.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* to_string)(struct _cef_view_t* self,
                                                 int include_children);

  ///
  // Returns true (1) if this View is valid.
  ///
  int(CEF_CALLBACK* is_valid)(struct _cef_view_t* self);

  ///
  // Returns true (1) if this View is currently attached to another View. A View
  // can only be attached to one View at a time.
  ///
  int(CEF_CALLBACK* is_attached)(struct _cef_view_t* self);

  ///
  // Returns true (1) if this View is the same as |that| View.
  ///
  int(CEF_CALLBACK* is_same)(struct _cef_view_t* self,
                             struct _cef_view_t* that);

  ///
  // Returns the delegate associated with this View, if any.
  ///
  struct _cef_view_delegate_t*(CEF_CALLBACK* get_delegate)(
      struct _cef_view_t* self);

  ///
  // Returns the top-level Window hosting this View, if any.
  ///
  struct _cef_window_t*(CEF_CALLBACK* get_window)(struct _cef_view_t* self);

  ///
  // Returns the ID for this View.
  ///
  int(CEF_CALLBACK* get_id)(struct _cef_view_t* self);

  ///
  // Sets the ID for this View. ID should be unique within the subtree that you
  // intend to search for it. 0 is the default ID for views.
  ///
  void(CEF_CALLBACK* set_id)(struct _cef_view_t* self, int id);

  ///
  // Returns the group id of this View, or -1 if not set.
  ///
  int(CEF_CALLBACK* get_group_id)(struct _cef_view_t* self);

  ///
  // A group id is used to tag Views which are part of the same logical group.
  // Focus can be moved between views with the same group using the arrow keys.
  // The group id is immutable once it's set.
  ///
  void(CEF_CALLBACK* set_group_id)(struct _cef_view_t* self, int group_id);

  ///
  // Returns the View that contains this View, if any.
  ///
  struct _cef_view_t*(CEF_CALLBACK* get_parent_view)(struct _cef_view_t* self);

  ///
  // Recursively descends the view tree starting at this View, and returns the
  // first child that it encounters with the given ID. Returns NULL if no
  // matching child view is found.
  ///
  struct _cef_view_t*(CEF_CALLBACK* get_view_for_id)(struct _cef_view_t* self,
                                                     int id);

  ///
  // Sets the bounds (size and position) of this View. |bounds| is in parent
  // coordinates, or DIP screen coordinates if there is no parent.
  ///
  void(CEF_CALLBACK* set_bounds)(struct _cef_view_t* self,
                                 const cef_rect_t* bounds);

  ///
  // Returns the bounds (size and position) of this View in parent coordinates,
  // or DIP screen coordinates if there is no parent.
  ///
  cef_rect_t(CEF_CALLBACK* get_bounds)(struct _cef_view_t* self);

  ///
  // Returns the bounds (size and position) of this View in DIP screen
  // coordinates.
  ///
  cef_rect_t(CEF_CALLBACK* get_bounds_in_screen)(struct _cef_view_t* self);

  ///
  // Sets the size of this View without changing the position. |size| in parent
  // coordinates, or DIP screen coordinates if there is no parent.
  ///
  void(CEF_CALLBACK* set_size)(struct _cef_view_t* self,
                               const cef_size_t* size);

  ///
  // Returns the size of this View in parent coordinates, or DIP screen
  // coordinates if there is no parent.
  ///
  cef_size_t(CEF_CALLBACK* get_size)(struct _cef_view_t* self);

  ///
  // Sets the position of this View without changing the size. |position| is in
  // parent coordinates, or DIP screen coordinates if there is no parent.
  ///
  void(CEF_CALLBACK* set_position)(struct _cef_view_t* self,
                                   const cef_point_t* position);

  ///
  // Returns the position of this View. Position is in parent coordinates, or
  // DIP screen coordinates if there is no parent.
  ///
  cef_point_t(CEF_CALLBACK* get_position)(struct _cef_view_t* self);

  ///
  // Sets the insets for this View. |insets| is in parent coordinates, or DIP
  // screen coordinates if there is no parent.
  ///
  void(CEF_CALLBACK* set_insets)(struct _cef_view_t* self,
                                 const cef_insets_t* insets);

  ///
  // Returns the insets for this View in parent coordinates, or DIP screen
  // coordinates if there is no parent.
  ///
  cef_insets_t(CEF_CALLBACK* get_insets)(struct _cef_view_t* self);

  ///
  // Returns the size this View would like to be if enough space is available.
  // Size is in parent coordinates, or DIP screen coordinates if there is no
  // parent.
  ///
  cef_size_t(CEF_CALLBACK* get_preferred_size)(struct _cef_view_t* self);

  ///
  // Size this View to its preferred size. Size is in parent coordinates, or DIP
  // screen coordinates if there is no parent.
  ///
  void(CEF_CALLBACK* size_to_preferred_size)(struct _cef_view_t* self);

  ///
  // Returns the minimum size for this View. Size is in parent coordinates, or
  // DIP screen coordinates if there is no parent.
  ///
  cef_size_t(CEF_CALLBACK* get_minimum_size)(struct _cef_view_t* self);

  ///
  // Returns the maximum size for this View. Size is in parent coordinates, or
  // DIP screen coordinates if there is no parent.
  ///
  cef_size_t(CEF_CALLBACK* get_maximum_size)(struct _cef_view_t* self);

  ///
  // Returns the height necessary to display this View with the provided width.
  ///
  int(CEF_CALLBACK* get_height_for_width)(struct _cef_view_t* self, int width);

  ///
  // Indicate that this View and all parent Views require a re-layout. This
  // ensures the next call to layout() will propagate to this View even if the
  // bounds of parent Views do not change.
  ///
  void(CEF_CALLBACK* invalidate_layout)(struct _cef_view_t* self);

  ///
  // Sets whether this View is visible. Windows are hidden by default and other
  // views are visible by default. This View and any parent views must be set as
  // visible for this View to be drawn in a Window. If this View is set as
  // hidden then it and any child views will not be drawn and, if any of those
  // views currently have focus, then focus will also be cleared. Painting is
  // scheduled as needed. If this View is a Window then calling this function is
  // equivalent to calling the Window show() and hide() functions.
  ///
  void(CEF_CALLBACK* set_visible)(struct _cef_view_t* self, int visible);

  ///
  // Returns whether this View is visible. A view may be visible but still not
  // drawn in a Window if any parent views are hidden. If this View is a Window
  // then a return value of true (1) indicates that this Window is currently
  // visible to the user on-screen. If this View is not a Window then call
  // is_drawn() to determine whether this View and all parent views are visible
  // and will be drawn.
  ///
  int(CEF_CALLBACK* is_visible)(struct _cef_view_t* self);

  ///
  // Returns whether this View is visible and drawn in a Window. A view is drawn
  // if it and all parent views are visible. If this View is a Window then
  // calling this function is equivalent to calling is_visible(). Otherwise, to
  // determine if the containing Window is visible to the user on-screen call
  // is_visible() on the Window.
  ///
  int(CEF_CALLBACK* is_drawn)(struct _cef_view_t* self);

  ///
  // Set whether this View is enabled. A disabled View does not receive keyboard
  // or mouse inputs. If |enabled| differs from the current value the View will
  // be repainted. Also, clears focus if the focused View is disabled.
  ///
  void(CEF_CALLBACK* set_enabled)(struct _cef_view_t* self, int enabled);

  ///
  // Returns whether this View is enabled.
  ///
  int(CEF_CALLBACK* is_enabled)(struct _cef_view_t* self);

  ///
  // Sets whether this View is capable of taking focus. It will clear focus if
  // the focused View is set to be non-focusable. This is false (0) by default
  // so that a View used as a container does not get the focus.
  ///
  void(CEF_CALLBACK* set_focusable)(struct _cef_view_t* self, int focusable);

  ///
  // Returns true (1) if this View is focusable, enabled and drawn.
  ///
  int(CEF_CALLBACK* is_focusable)(struct _cef_view_t* self);

  ///
  // Return whether this View is focusable when the user requires full keyboard
  // access, even though it may not be normally focusable.
  ///
  int(CEF_CALLBACK* is_accessibility_focusable)(struct _cef_view_t* self);

  ///
  // Request keyboard focus. If this View is focusable it will become the
  // focused View.
  ///
  void(CEF_CALLBACK* request_focus)(struct _cef_view_t* self);

  ///
  // Sets the background color for this View.
  ///
  void(CEF_CALLBACK* set_background_color)(struct _cef_view_t* self,
                                           cef_color_t color);

  ///
  // Returns the background color for this View.
  ///
  cef_color_t(CEF_CALLBACK* get_background_color)(struct _cef_view_t* self);

  ///
  // Convert |point| from this View's coordinate system to DIP screen
  // coordinates. This View must belong to a Window when calling this function.
  // Returns true (1) if the conversion is successful or false (0) otherwise.
  // Use cef_display_t::convert_point_to_pixels() after calling this function if
  // further conversion to display-specific pixel coordinates is desired.
  ///
  int(CEF_CALLBACK* convert_point_to_screen)(struct _cef_view_t* self,
                                             cef_point_t* point);

  ///
  // Convert |point| to this View's coordinate system from DIP screen
  // coordinates. This View must belong to a Window when calling this function.
  // Returns true (1) if the conversion is successful or false (0) otherwise.
  // Use cef_display_t::convert_point_from_pixels() before calling this function
  // if conversion from display-specific pixel coordinates is necessary.
  ///
  int(CEF_CALLBACK* convert_point_from_screen)(struct _cef_view_t* self,
                                               cef_point_t* point);

  ///
  // Convert |point| from this View's coordinate system to that of the Window.
  // This View must belong to a Window when calling this function. Returns true
  // (1) if the conversion is successful or false (0) otherwise.
  ///
  int(CEF_CALLBACK* convert_point_to_window)(struct _cef_view_t* self,
                                             cef_point_t* point);

  ///
  // Convert |point| to this View's coordinate system from that of the Window.
  // This View must belong to a Window when calling this function. Returns true
  // (1) if the conversion is successful or false (0) otherwise.
  ///
  int(CEF_CALLBACK* convert_point_from_window)(struct _cef_view_t* self,
                                               cef_point_t* point);

  ///
  // Convert |point| from this View's coordinate system to that of |view|.
  // |view| needs to be in the same Window but not necessarily the same view
  // hierarchy. Returns true (1) if the conversion is successful or false (0)
  // otherwise.
  ///
  int(CEF_CALLBACK* convert_point_to_view)(struct _cef_view_t* self,
                                           struct _cef_view_t* view,
                                           cef_point_t* point);

  ///
  // Convert |point| to this View's coordinate system from that |view|. |view|
  // needs to be in the same Window but not necessarily the same view hierarchy.
  // Returns true (1) if the conversion is successful or false (0) otherwise.
  ///
  int(CEF_CALLBACK* convert_point_from_view)(struct _cef_view_t* self,
                                             struct _cef_view_t* view,
                                             cef_point_t* point);
} cef_view_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_VIEWS_CEF_VIEW_CAPI_H_
