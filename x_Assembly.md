rax
このレジスタに値を入れて関数は返り値を返す

rdi
第1引数
rsi
第2引数
rdx
第3引数
rcx
第4引数



section .text
プログラムのうち、機械語の部分を格納するためのセクションです。プログラムローダは、実行可能なメモリ領域を確保した後、セクションのデータ(機械語, プログラムコード)を書き込みます。

section .data
プログラムのうち、初期値を持つ変数を格納するためのセクションです。C言語では、「0以外の初期値を持つ大域変数」「0以外の初期値を持つ静的局所変数」がここに置かれます。データとして初期値を持ち、プログラムローダは書き込み可能なメモリを確保した後、初期値を書き込みます。