/* GTK - The GIMP Toolkit
 * Copyright (C) 2010 Carlos Garnacho <carlosg@gnome.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GTK_THEMING_ENGINE_PRIVATE_H__
#define __GTK_THEMING_ENGINE_PRIVATE_H__

#include <gdk/gdk.h>
#include "gtk/gtkthemingengine.h"
#include "gtk/gtkcssvalueprivate.h"

void _gtk_theming_engine_paint_spinner (cairo_t       *cr,
                                        gdouble        radius,
                                        gdouble        progress,
                                        const GdkRGBA *color);

GtkCssValue  *_gtk_theming_engine_peek_property (GtkThemingEngine *engine,
                                                 guint             property_id);
void          _gtk_theming_engine_set_context   (GtkThemingEngine *engine,
                                                 GtkStyleContext  *context);
GtkStyleContext *_gtk_theming_engine_get_context   (GtkThemingEngine *engine);

#endif /* __GTK_THEMING_ENGINE_PRIVATE_H__ */
