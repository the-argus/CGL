/* GTK - The GIMP Toolkit
 * Copyright (C) 2012 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GTK_COLOR_CHOOSER_DIALOG_H__
#define __GTK_COLOR_CHOOSER_DIALOG_H__

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gtk/gtkdialog.h>

G_BEGIN_DECLS

#define GTK_TYPE_COLOR_CHOOSER_DIALOG              (gtk_color_chooser_dialog_get_type ())
#define GTK_COLOR_CHOOSER_DIALOG(obj)              (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_COLOR_CHOOSER_DIALOG, GtkColorChooserDialog))
#define GTK_COLOR_CHOOSER_DIALOG_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_COLOR_CHOOSER_DIALOG, GtkColorChooserDialogClass))
#define GTK_IS_COLOR_CHOOSER_DIALOG(obj)           (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_COLOR_CHOOSER_DIALOG))
#define GTK_IS_COLOR_CHOOSER_DIALOG_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_COLOR_CHOOSER_DIALOG))
#define GTK_COLOR_CHOOSER_DIALOG_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_COLOR_CHOOSER_DIALOG, GtkColorChooserDialogClass))

typedef struct _GtkColorChooserDialog        GtkColorChooserDialog;
typedef struct _GtkColorChooserDialogPrivate GtkColorChooserDialogPrivate;
typedef struct _GtkColorChooserDialogClass   GtkColorChooserDialogClass;

struct _GtkColorChooserDialog
{
  GtkDialog parent_instance;

  /*< private >*/
  GtkColorChooserDialogPrivate *priv;
};

struct _GtkColorChooserDialogClass
{
  GtkDialogClass parent_class;

  /* Padding for future expansion */
  void (*_gtk_reserved1) (void);
  void (*_gtk_reserved2) (void);
  void (*_gtk_reserved3) (void);
  void (*_gtk_reserved4) (void);
};

GType       gtk_color_chooser_dialog_get_type (void) G_GNUC_CONST;
GtkWidget * gtk_color_chooser_dialog_new      (const gchar *title,
                                               GtkWindow   *parent);

G_END_DECLS

#endif /* __GTK_COLOR_CHOOSER_DIALOG_H__ */
