$NetBSD: patch-setup.py,v 1.3 2021/08/02 20:30:24 adam Exp $

Use setuptools.

--- setup.py.orig	2021-08-02 20:14:20.000000000 +0000
+++ setup.py
@@ -1,7 +1,7 @@
 #!/usr/bin/env python
 # setup.py generated by flit for tools that don't yet use PEP 517
 
-from distutils.core import setup
+from setuptools import setup
 
 packages = \
 ['pyphen']
