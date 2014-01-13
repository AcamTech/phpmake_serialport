Gorilla PHPMake\SerialPort
==========================
The PHP extension for communicate other device via serial-port(COM).  
This module is able to run on POSIX system and Windows.

シリアルポート(COM)を介して他のデバイスと通信を行うための PHP 拡張です。  
このモジュールは Linux などの POSIX システムと Windows で動作します。

This is a standalone PHP extension created using CodeGen_PECL 1.1.3

HACKING
=======

There are two ways to modify an extension created using CodeGen_PECL:

1) you can modify the generated code as with any other PHP extension
  
2) you can add custom code to the CodeGen_PECL XML source and re-run pecl-gen

The 2nd approach may look a bit complicated but you have be aware that any
manual changes to the generated code will be lost if you ever change the
XML specs and re-run PECL-Gen. All changes done before have to be applied
to the newly generated code again.
Adding code snippets to the XML source itself on the other hand may be a 
bit more complicated but this way your custom code will always be in the
generated code no matter how often you rerun CodeGen_PECL.


BUILDING ON UNIX etc.
=====================

To compile your new extension, you will have to execute the following steps:

1.  $ ./phpize
2.  $ ./configure [--enable--Gorilla] 
3.  $ make
4.  $ make test
5.  $ [sudo] make install



BUILDING ON WINDOWS
===================

The extension provides the VisualStudio V6 project file 

  Gorilla.dsp
To compile the extension you open this file using VisualStudio,
select the apropriate configuration for your installation
(either "Release_TS" or "Debug_TS") and create "php_Gorilla.dll"

After successfull compilation you have to copy the newly
created "Gorilla.dll" to the PHP
extension directory (default: C:\PHP\extensions).


TESTING
=======

You can now load the extension using a php.ini directive

  extension="Gorilla.[so|dll]"

or load it at runtime using the dl() function

  dl("Gorilla.[so|dll]");

The extension should now be available, you can test this
using the extension_loaded() function:

  if (extension_loaded("Gorilla"))
    echo "Gorilla loaded :)";
  else
    echo "something is wrong :(";

The extension will also add its own block to the output
of phpinfo();

