/* GTK - The GIMP Toolkit
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
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

/*
 * Modified by the GTK+ Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/.
 */

#ifndef __GTK_IMAGE_H__
#define __GTK_IMAGE_H__


#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gio/gio.h>
#include <gtk/gtkmisc.h>


G_BEGIN_DECLS

#define GTK_TYPE_IMAGE                  (gtk_image_get_type ())
#define GTK_IMAGE(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_IMAGE, GtkImage))
#define GTK_IMAGE_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_IMAGE, GtkImageClass))
#define GTK_IS_IMAGE(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_IMAGE))
#define GTK_IS_IMAGE_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_IMAGE))
#define GTK_IMAGE_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_IMAGE, GtkImageClass))


typedef struct _GtkImage              GtkImage;
typedef struct _GtkImagePrivate       GtkImagePrivate;
typedef struct _GtkImageClass         GtkImageClass;

/**
 * GtkImageType:
 * @GTK_IMAGE_EMPTY: there is no image displayed by the widget
 * @GTK_IMAGE_PIXBUF: the widget contains a #GdkPixbuf
 * @GTK_IMAGE_STOCK: the widget contains a stock icon name (see
 *  <xref linkend="gtk3-Stock-Items"/>)
 * @GTK_IMAGE_ICON_SET: the widget contains a #GtkIconSet
 * @GTK_IMAGE_ANIMATION: the widget contains a #GdkPixbufAnimation
 * @GTK_IMAGE_ICON_NAME: the widget contains a named icon.
 *  This image type was added in GTK+ 2.6
 * @GTK_IMAGE_GICON: the widget contains a #GIcon.
 *  This image type was added in GTK+ 2.14
 * @GTK_IMAGE_SURFACE: the widget contains a #cairo_surface_t.
 *  This image type was added in GTK+ 3.10
 *
 * Describes the image data representation used by a #GtkImage. If you
 * want to get the image from the widget, you can only get the
 * currently-stored representation. e.g.  if the
 * gtk_image_get_storage_type() returns #GTK_IMAGE_PIXBUF, then you can
 * call gtk_image_get_pixbuf() but not gtk_image_get_stock().  For empty
 * images, you can request any storage type (call any of the "get"
 * functions), but they will all return %NULL values.
 */
typedef enum
{
  GTK_IMAGE_EMPTY,
  GTK_IMAGE_PIXBUF,
  GTK_IMAGE_STOCK,
  GTK_IMAGE_ICON_SET,
  GTK_IMAGE_ANIMATION,
  GTK_IMAGE_ICON_NAME,
  GTK_IMAGE_GICON,
  GTK_IMAGE_SURFACE
} GtkImageType;

/**
 * GtkImage:
 *
 * This struct contain private data only and should be accessed by the functions
 * below.
 */
struct _GtkImage
{
  GtkMisc misc;

  /*< private >*/
  GtkImagePrivate *priv;
};

struct _GtkImageClass
{
  GtkMiscClass parent_class;

  /* Padding for future expansion */
  void (*_gtk_reserved1) (void);
  void (*_gtk_reserved2) (void);
  void (*_gtk_reserved3) (void);
  void (*_gtk_reserved4) (void);
};

GType      gtk_image_get_type (void) G_GNUC_CONST;

GtkWidget* gtk_image_new                (void);
GtkWidget* gtk_image_new_from_file      (const gchar     *filename);
GtkWidget* gtk_image_new_from_resource  (const gchar     *resource_path);
GtkWidget* gtk_image_new_from_pixbuf    (GdkPixbuf       *pixbuf);
GtkWidget* gtk_image_new_from_stock     (const gchar     *stock_id,
                                         GtkIconSize      size);
GtkWidget* gtk_image_new_from_icon_set  (GtkIconSet      *icon_set,
                                         GtkIconSize      size);
GtkWidget* gtk_image_new_from_animation (GdkPixbufAnimation *animation);
GtkWidget* gtk_image_new_from_icon_name (const gchar     *icon_name,
					 GtkIconSize      size);
GtkWidget* gtk_image_new_from_gicon     (GIcon           *icon,
					 GtkIconSize      size);
GDK_AVAILABLE_IN_3_10
GtkWidget* gtk_image_new_from_surface   (cairo_surface_t *surface);

void gtk_image_clear              (GtkImage        *image);
void gtk_image_set_from_file      (GtkImage        *image,
                                   const gchar     *filename);
void gtk_image_set_from_resource  (GtkImage        *image,
                                   const gchar     *resource_path);
void gtk_image_set_from_pixbuf    (GtkImage        *image,
                                   GdkPixbuf       *pixbuf);
void gtk_image_set_from_stock     (GtkImage        *image,
                                   const gchar     *stock_id,
                                   GtkIconSize      size);
void gtk_image_set_from_icon_set  (GtkImage        *image,
                                   GtkIconSet      *icon_set,
                                   GtkIconSize      size);
void gtk_image_set_from_animation (GtkImage           *image,
                                   GdkPixbufAnimation *animation);
void gtk_image_set_from_icon_name (GtkImage        *image,
				   const gchar     *icon_name,
				   GtkIconSize      size);
void gtk_image_set_from_gicon     (GtkImage        *image,
				   GIcon           *icon,
				   GtkIconSize      size);
void gtk_image_set_pixel_size     (GtkImage        *image,
				   gint             pixel_size);

GtkImageType gtk_image_get_storage_type (GtkImage   *image);

GdkPixbuf* gtk_image_get_pixbuf   (GtkImage         *image);
void       gtk_image_get_stock    (GtkImage         *image,
                                   gchar           **stock_id,
                                   GtkIconSize      *size);
void       gtk_image_get_icon_set (GtkImage         *image,
                                   GtkIconSet      **icon_set,
                                   GtkIconSize      *size);
GdkPixbufAnimation* gtk_image_get_animation (GtkImage *image);
void       gtk_image_get_icon_name (GtkImage     *image,
				    const gchar **icon_name,
				    GtkIconSize  *size);
void       gtk_image_get_gicon     (GtkImage              *image,
				    GIcon                **gicon,
				    GtkIconSize           *size);
gint       gtk_image_get_pixel_size (GtkImage             *image);
void gtk_image_set_from_surface   (GtkImage        *image,
				   cairo_surface_t *surface);
G_END_DECLS

#endif /* __GTK_IMAGE_H__ */
