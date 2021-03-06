/*
 * videoarch.h - Native GTK3 graphics routines.
 *
 * based on the X11 version written by
 *  Ettore Perazzoli
 *  Teemu Rantanen <tvr@cs.hut.fi>
 *  Andreas Boose <viceteam@t-online.de>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */
#ifndef VICE_VIDEOARCH_H
#define VICE_VIDEOARCH_H

#include "vice.h"

#include "viewport.h"
#include "video.h"


/* This file will need to be fixed for native GTK3 usage */

#include <gtk/gtk.h>

#ifdef HAVE_HWSCALE
#include <GL/gl.h>
#endif

struct video_canvas_s {
    unsigned int initialized;
    unsigned int created;

    /* GtkGlArea widget to render to */
    GtkWidget *widget;

#if 0
    GtkWidget *emuwindow, *pane;
#if !defined(HAVE_CAIRO)
    /* deprecated since 2.22, removed in 3.0 */
    GdkImage *gdk_image;
#else
    GdkPixbuf *gdk_pixbuf;
    cairo_t *cairo_ctx;
#endif
#endif
    struct video_render_config_s *videoconfig;
    struct draw_buffer_s *draw_buffer;
    struct viewport_s *viewport;
    struct geometry_s *geometry;
    struct palette_s *palette;
    float refreshrate; /* currently displayed refresh rate */

    struct video_draw_buffer_callback_s *video_draw_buffer_callback;
#ifdef HAVE_FULLSCREEN
    struct fullscreenconfig_s *fullscreenconfig;
#endif
#ifdef HAVE_HWSCALE
    unsigned char *hwscale_image;
    GLuint screen_texture;
#endif
    int offx; /* for lightpen */
    int app_shell; /* app shell that belongs to this canvas */
};
typedef struct video_canvas_s video_canvas_t;

#endif
