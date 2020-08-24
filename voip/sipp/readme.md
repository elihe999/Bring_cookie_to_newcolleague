# sipp

<http://sipp.sourceforge.net/index.html>
<http://sipp.sourceforge.net/doc/reference.html>
<https://sourceforge.net/projects/sipp/files/sipp/>

## install

> sudo apt-get install libncurses5-dev

On Linux, SIPp is provided in the form of source code. You will need to compile SIPp to actually use it.
Pre-requisites to compile SIPp are :
C++ Compiler
curses or ncurses library
For TLS support: OpenSSL >= 0.9.8
For pcap play support: libpcap and libnet
For SCTP support: lksctp-tools
For distributed pauses: Gnu Scientific Libraries

You have four options to compile SIPp:
Without TLS (Transport Layer Security), SCTP or PCAP support: - This is the recommended setup if you don't need to handle SCTP, TLS or PCAP.

```bash
 # tar -xvzf sipp-xxx.tar
              # cd sipp
              # ./configure
              # make
```   
With TLS support, you must have installed OpenSSL library (>=0.9.8) (which may come with your system). Building SIPp consists only in adding the "--with-openssl" option to the configure command:

```bash
# tar -xvzf sipp-xxx.tar.gz
            # cd sipp
            # ./configure --with-openssl
            # make
            
With PCAP play support:
# tar -xvzf sipp-xxx.tar.gz
            # cd sipp
            # ./configure --with-pcap
            # make
            
With SCTP support:
# tar -xvzf sipp-xxx.tar.gz
            # cd sipp
            # ./configure --with-sctp
            # make
            
You can also combine these various options, e.g.::
# tar -xvzf sipp-xxx.tar.gz
            # cd sipp
            # ./configure --with-sctp --with-pcap --with-openssl
            # make
```        
