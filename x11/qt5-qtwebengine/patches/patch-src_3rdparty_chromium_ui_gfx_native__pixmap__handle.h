$NetBSD: patch-src_3rdparty_chromium_ui_gfx_native__pixmap__handle.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/gfx/native_pixmap_handle.h.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/native_pixmap_handle.h
@@ -15,7 +15,7 @@
 #include "build/build_config.h"
 #include "ui/gfx/gfx_export.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/files/scoped_file.h"
 #endif
 
@@ -32,7 +32,7 @@ struct GFX_EXPORT NativePixmapPlane {
   NativePixmapPlane(int stride,
                     int offset,
                     uint64_t size
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                     ,
                     base::ScopedFD fd
 #elif defined(OS_FUCHSIA)
@@ -53,7 +53,7 @@ struct GFX_EXPORT NativePixmapPlane {
   // This is necessary to map the buffers.
   uint64_t size;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // File descriptor for the underlying memory object (usually dmabuf).
   base::ScopedFD fd;
 #elif defined(OS_FUCHSIA)
@@ -82,7 +82,7 @@ struct GFX_EXPORT NativePixmapHandle {
 
   std::vector<NativePixmapPlane> planes;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // The modifier is retrieved from GBM library and passed to EGL driver.
   // Generally it's platform specific, and we don't need to modify it in
   // Chromium code. Also one per plane per entry.
