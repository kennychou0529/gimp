/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * gimpoperationlayermode.h
 * Copyright (C) 2008 Michael Natterer <mitch@gimp.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __GIMP_OPERATION_LAYER_MODE_H__
#define __GIMP_OPERATION_LAYER_MODE_H__


#include <gegl-plugin.h>
#include <operation/gegl-operation-point-composer.h>


#define GIMP_TYPE_OPERATION_LAYER_MODE            (gimp_operation_layer_mode_get_type ())
#define GIMP_OPERATION_LAYER_MODE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIMP_TYPE_OPERATION_LAYER_MODE, GimpOperationLayerMode))
#define GIMP_OPERATION_LAYER_MODE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  GIMP_TYPE_OPERATION_LAYER_MODE, GimpOperationLayerModeClass))
#define GIMP_IS_OPERATION_LAYER_MODE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIMP_TYPE_OPERATION_LAYER_MODE))
#define GIMP_IS_OPERATION_LAYER_MODE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GIMP_TYPE_OPERATION_LAYER_MODE))
#define GIMP_OPERATION_LAYER_MODE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  GIMP_TYPE_OPERATION_LAYER_MODE, GimpOperationLayerModeClass))


typedef struct _GimpOperationLayerModeClass GimpOperationLayerModeClass;

struct _GimpOperationLayerMode
{
  GeglOperationPointComposer  parent_instance;
};

struct _GimpOperationLayerModeClass
{
  GeglOperationPointComposerClass  parent_class;

  gboolean (* process) (GeglOperation       *operation,
                        void                *in_buf,
                        void                *aux_buf,
                        void                *out_buf,
                        glong                samples,
                        const GeglRectangle *roi);
};


GType   gimp_operation_layer_mode_get_type (void) G_GNUC_CONST;


#endif /* __GIMP_OPERATION_LAYER_MODE_H__ */