# Assembler
 
ASSEMBLER DERLEYİCİSİ

Programlama Dilleri (derleyiciler) giriş olarak yazılan bir programın kaynak kodunu alır (kodun 
doğru yazıldığı varsayılır) ve ondan sonra kaynak kod program ne iş yapıyorsa, kendiside aynı işi 
yapan programı yazar. Bu düşünce ile 8-bitlik bir El-Ceziri işlemcisinin olduğu varsayılsın. Bu 
işlemcinin RAM 8-bitlik 2 KB’lık belleği (hafıza) bulunmaktadır.

Aynı zamanda üzerinde AX, BX, CX, DX şeklin dört tane 8-bitlik kayıtçı (register) bulunmaktadır.

Bu işlemcinin komut kümesi aşağıdaki listede verilmiştir.

HRK X1,X2 // bu komutun anlamı X1=X2

TOP X1,X2 // bu komutun anlamı X1=X1+X2

CRP X1,X2 // bu komutun anlamı X1=X1*X2

CIK X1,X2 // bu komutun anlamı X1=X1-X2

BOL X1,X2 // bu komutun anlamı: tam kısmı X1=X1/X2 ve DX=X1 mod X2

VE X1,X2 // bu komutun anlamı X1=X1 & X2

VEYA X1,X2 // bu komutun anlamı X1=X1 | X2

DEG X1 // bu komutun anlamı 𝑋1 değerinin ikili tabanda 0 ise 1 ve 1 ise 0 yapan komut.

SS ETIKET // Bu komutun anlamı bu komuttan önce yapılan işlemin sonucu sıfırsa, ETIKET olarak 
verilen yere gider.

SSD ETIKET // Bu komutun anlamı bu komuttan önce yapılan işlemin sonucu sıfır değilse, ETIKET olarak 
verilen yere gider.

SN ETIKET // Bu komutun anlamı bu komuttan önce yapılan işlemin sonucu negatifse, ETIKET olarak 
verilen yere gider.

SP ETIKET // Bu komutun anlamı bu komuttan önce yapılan işlemin sonucu pozitifse, ETIKET olarak 
verilen yere gider.

Verilen komut kümesinde TOP, CRP, CIK, BOL, VE, VEYA komutlarında operandlarından ilki kayıtçı 
olması zorunludur.
TOP AX,BX // Bu komutta her iki operand kayıtçıdır.
TOP AX,125 // Bu komutta birinci operand AX kayıtçısı ve ikincisi ise normal literaldir.
TOP AX,[ADRES] // Bu komutta birinci operand AX kayıtçısı ve ikincisi ise RAM’in ADRES yeridir.

Kod çalıştırıldıktan sonra AX,BX,CX,DX son durumları yazdırılacaktır.