$NetBSD: patch-src_3rdparty_chromium_base_process_process__metrics.h,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/process/process_metrics.h.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/process/process_metrics.h
@@ -44,7 +44,7 @@ namespace base {
 // Full declaration is in process_metrics_iocounters.h.
 struct IoCounters;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 // Minor and major page fault counts since the process creation.
 // Both counts are process-wide, and exclude child processes.
 //
@@ -95,7 +95,7 @@ class BASE_EXPORT ProcessMetrics {
   // convenience wrapper for CreateProcessMetrics().
   static std::unique_ptr<ProcessMetrics> CreateCurrentProcessMetrics();
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Resident Set Size is a Linux/Android specific memory concept. Do not
   // attempt to extend this to other platforms.
   BASE_EXPORT size_t GetResidentSetSize() const;
@@ -186,7 +186,7 @@ class BASE_EXPORT ProcessMetrics {
   int GetOpenFdSoftLimit() const;
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Bytes of swap as reported by /proc/[pid]/status.
   uint64_t GetVmSwapBytes() const;
 
@@ -205,7 +205,7 @@ class BASE_EXPORT ProcessMetrics {
   ProcessMetrics(ProcessHandle process, PortProvider* port_provider);
 #endif  // !defined(OS_MACOSX) || defined(OS_IOS)
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   int CalculateIdleWakeupsPerSecond(uint64_t absolute_idle_wakeups);
 #endif
 #if defined(OS_MACOSX)
@@ -234,7 +234,7 @@ class BASE_EXPORT ProcessMetrics {
   // Number of bytes transferred to/from disk in bytes.
   uint64_t last_cumulative_disk_usage_ = 0;
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   // Same thing for idle wakeups.
   TimeTicks last_idle_wakeups_time_;
   uint64_t last_absolute_idle_wakeups_;
@@ -286,7 +286,8 @@ BASE_EXPORT void IncreaseFdLimitTo(unsig
 #endif  // defined(OS_POSIX)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA)
+    defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA) || \
+    defined(OS_BSD)
 // Data about system-wide memory consumption. Values are in KB. Available on
 // Windows, Mac, Linux, Android and Chrome OS.
 //
@@ -319,7 +320,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
   int avail_phys = 0;
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
   // This provides an estimate of available memory as described here:
   // https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/commit/?id=34e431b0ae398fc54ea69ff85ec700722c9da773
   // NOTE: this is ONLY valid in kernels 3.14 and up.  Its value will always
@@ -334,7 +335,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
 #endif
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_AIX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   int buffers = 0;
   int cached = 0;
   int active_anon = 0;
@@ -372,7 +373,7 @@ BASE_EXPORT bool GetSystemMemoryInfo(Sys
 #endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
         // defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
 // Parse the data found in /proc/<pid>/stat and return the sum of the
 // CPU-related ticks.  Returns -1 on parse error.
 // Exposed for testing.
@@ -540,7 +541,7 @@ class BASE_EXPORT SystemMetrics {
   FRIEND_TEST_ALL_PREFIXES(SystemMetricsTest, SystemMetrics);
 
   size_t committed_memory_;
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   SystemMemoryInfoKB memory_info_;
   VmStatInfo vmstat_info_;
   SystemDiskInfo disk_info_;
