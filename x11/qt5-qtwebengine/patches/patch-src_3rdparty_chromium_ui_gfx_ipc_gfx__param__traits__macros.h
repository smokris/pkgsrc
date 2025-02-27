$NetBSD: patch-src_3rdparty_chromium_ui_gfx_ipc_gfx__param__traits__macros.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/gfx/ipc/gfx_param_traits_macros.h.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/ipc/gfx_param_traits_macros.h
@@ -18,7 +18,7 @@
 #include "ui/gfx/selection_bound.h"
 #include "ui/gfx/swap_result.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/gfx/native_pixmap_handle.h"
 #endif
 
@@ -51,7 +51,7 @@ IPC_STRUCT_TRAITS_BEGIN(gfx::GpuMemoryBu
   IPC_STRUCT_TRAITS_MEMBER(region)
   IPC_STRUCT_TRAITS_MEMBER(offset)
   IPC_STRUCT_TRAITS_MEMBER(stride)
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(native_pixmap_handle)
 #elif defined(OS_MACOSX)
   IPC_STRUCT_TRAITS_MEMBER(mach_port)
@@ -66,12 +66,12 @@ IPC_STRUCT_TRAITS_BEGIN(gfx::GpuMemoryBu
   IPC_STRUCT_TRAITS_MEMBER(id)
 IPC_STRUCT_TRAITS_END()
 
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 IPC_STRUCT_TRAITS_BEGIN(gfx::NativePixmapPlane)
   IPC_STRUCT_TRAITS_MEMBER(stride)
   IPC_STRUCT_TRAITS_MEMBER(offset)
   IPC_STRUCT_TRAITS_MEMBER(size)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(fd)
 #elif defined(OS_FUCHSIA)
   IPC_STRUCT_TRAITS_MEMBER(vmo)
@@ -80,7 +80,7 @@ IPC_STRUCT_TRAITS_END()
 
 IPC_STRUCT_TRAITS_BEGIN(gfx::NativePixmapHandle)
   IPC_STRUCT_TRAITS_MEMBER(planes)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(modifier)
 #endif
 #if defined(OS_FUCHSIA)
