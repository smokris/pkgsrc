$NetBSD: patch-ncurses_tinfo_captoinfo.c,v 1.1 2021/10/09 07:52:36 wiz Exp $

Fix for CVE-2021-39537 from upstream:
https://github.com/ThomasDickey/ncurses-snapshots/commit/63ca9e061f4644795d6f3f559557f3e1ed8c738b#diff-7e95c7bc5f213e9be438e69a9d5d0f261a14952bcbd692f7b9014217b8047340

--- ncurses/tinfo/captoinfo.c.orig	2020-02-02 23:34:34.000000000 +0000
+++ ncurses/tinfo/captoinfo.c
@@ -216,12 +216,15 @@ cvtchar(register const char *sp)
 	}
 	break;
     case '^':
+	len = 2;
 	c = UChar(*++sp);
-	if (c == '?')
+        if (c == '?') {
 	    c = 127;
-	else
+        } else if (c == '\0') {
+            len = 1;
+        } else {
 	    c &= 0x1f;
-	len = 2;
+	}
 	break;
     default:
 	c = UChar(*sp);
