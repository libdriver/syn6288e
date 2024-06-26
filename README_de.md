[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SYN6288E

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/syn6288e/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE) 

Der chinesische Sprachsynthese-Chip SYN6288E ist ein Mittel- und High-End-Sprachsynthese-Chip mit höherer Kostenleistung und natürlicherem Effekt, der Anfang 2010 von Beijing Yuyintianxia Technology Co., Ltd. auf den Markt gebracht wurde. SYN6288E empfängt den zu synthetisierenden Text über die asynchrone serielle Schnittstelle zu Realisieren Sie die Konvertierung von Text in Ton (TTS). Der neueste Sprachsynthese-Chip SYN6288E erbt die hervorragenden Eigenschaften von OSYNO6188: das kleinste LQFP32L-Chippaket, einfache Hardwareschnittstelle und hohe Kostenleistung; Darüber hinaus ist die Texterkennung von SYN6288E intelligenter, die Sprachsynthese natürlicher und der Sprachsyntheseeffekt und der intelligente Erkennungseffekt wurden erheblich verbessert. Es ist ein Sprachsynthese-Chip für High-End-Anwendungen.

LibDriver SYN6288E ist der voll funktionsfähige Treiber von SYN6288E, der von LibDriver gestartet wurde. Er bietet Textsynthese, Musiksynthese, Alarmtonsynthese und andere Funktionen. LibDriver ist MISRA-konform.

### Inhaltsverzeichnis

  - [Anweisung](#Anweisung)
  - [Installieren](#Installieren)
  - [Nutzung](#Nutzung)
    - [example basic](#example-basic)
    - [example advance](#example-advance)
  - [Dokument](#Dokument)
  - [Beitrag](#Beitrag)
  - [Lizenz](#Lizenz)
  - [Kontaktieren Sie uns](#Kontaktieren-Sie-uns)

### Anweisung

/src enthält LibDriver SYN6288E-Quelldateien.

/interface enthält die plattformunabhängige Vorlage LibDriver SYN6288E UART.

/test enthält den Testcode des LibDriver SYN6288E-Treibers und dieser Code kann die erforderliche Funktion des Chips einfach testen.

/example enthält LibDriver SYN6288E-Beispielcode.

/doc enthält das LibDriver SYN6288E-Offlinedokument.

/Datenblatt enthält SYN6288E-Datenblatt.

/project enthält den allgemeinen Beispielcode für Linux- und MCU-Entwicklungsboards. Alle Projekte verwenden das Shell-Skript, um den Treiber zu debuggen, und die detaillierten Anweisungen finden Sie in der README.md jedes Projekts.

/misra enthält die Ergebnisse des LibDriver MISRA Code Scans.

### Installieren

Verweisen Sie auf eine plattformunabhängige UART-Schnittstellenvorlage und stellen Sie Ihren Plattform-UART-Treiber fertig.

Fügen Sie das Verzeichnis /src, den Schnittstellentreiber für Ihre Plattform und Ihre eigenen Treiber zu Ihrem Projekt hinzu. Wenn Sie die Standardbeispieltreiber verwenden möchten, fügen Sie das Verzeichnis /example zu Ihrem Projekt hinzu.

### Nutzung

Sie können auf die Beispiele im Verzeichnis /example zurückgreifen, um Ihren eigenen Treiber zu vervollständigen. Wenn Sie die Standardprogrammierbeispiele verwenden möchten, erfahren Sie hier, wie Sie diese verwenden.

#### example basic

```C
#include "driver_syn6288e_basic.h"

uint8_t res;

res = syn6288e_basic_init();
if (res != 0)
{
    return 1;
}

...

res = syn6288e_basic_synthesis("你好");
if (res != 0)
{
    (void)syn6288e_basic_deinit();

    return 1;
}
(void)syn6288e_basic_sync();

...

(void)syn6288e_basic_deinit();

return 0;
```

#### example advance

```c
#include "driver_syn6288e_advance.h"

uint8_t res;

res = syn6288e_advance_init();
if (res != 0)
{
    return 1;
}

...

res = syn6288e_advance_synthesis("你好");
if (res != 0)
{
    (void)syn6288e_advance_deinit();

    return 1;
}
(void)syn6288e_advance_sync();

...

res = syn6288e_advance_sound(SYN6288E_SOUND_A);
if (res != 0)
{
    (void)syn6288e_advance_deinit();

    return 1;
}
(void)syn6288e_advance_sync()    

...
    
res = syn6288e_advance_message(SYN6288E_MESSAGE_A);
if (res != 0)
{
    (void)syn6288e_advance_deinit();

    return 1;
}
(void)syn6288e_advance_sync();

...

res = syn6288e_advance_ring(SYN6288E_RING_A);
if (res != 0)
{
    (void)syn6288e_advance_deinit();

    return 1;
}
(void)syn6288e_advance_sync();

...
    
(void)syn6288e_advance_deinit();

return 0;
```

### Dokument

Online-Dokumente: [https://www.libdriver.com/docs/syn6288e/index.html](https://www.libdriver.com/docs/syn6288e/index.html).

Offline-Dokumente: /doc/html/index.html.

### Beitrag

Bitte beachten Sie CONTRIBUTING.md.

### Lizenz

Urheberrechte © (c) 2015 - Gegenwart LibDriver Alle Rechte vorbehalten



Die MIT-Lizenz (MIT)



Hiermit wird jeder Person kostenlos die Erlaubnis erteilt, eine Kopie zu erhalten

dieser Software und zugehörigen Dokumentationsdateien (die „Software“) zu behandeln

in der Software ohne Einschränkung, einschließlich, aber nicht beschränkt auf die Rechte

zu verwenden, zu kopieren, zu modifizieren, zusammenzuführen, zu veröffentlichen, zu verteilen, unterzulizenzieren und/oder zu verkaufen

Kopien der Software und Personen, denen die Software gehört, zu gestatten

dazu eingerichtet werden, unter folgenden Bedingungen:



Der obige Urheberrechtshinweis und dieser Genehmigungshinweis müssen in allen enthalten sein

Kopien oder wesentliche Teile der Software.



DIE SOFTWARE WIRD "WIE BESEHEN" BEREITGESTELLT, OHNE JEGLICHE GEWÄHRLEISTUNG, AUSDRÜCKLICH ODER

STILLSCHWEIGEND, EINSCHLIESSLICH, ABER NICHT BESCHRÄNKT AUF DIE GEWÄHRLEISTUNG DER MARKTGÄNGIGKEIT,

EIGNUNG FÜR EINEN BESTIMMTEN ZWECK UND NICHTVERLETZUNG VON RECHTEN DRITTER. IN KEINEM FALL DARF DAS

AUTOREN ODER URHEBERRECHTSINHABER HAFTEN FÜR JEGLICHE ANSPRÜCHE, SCHÄDEN ODER ANDERE

HAFTUNG, OB AUS VERTRAG, DELIKT ODER ANDERWEITIG, ENTSTEHEND AUS,

AUS ODER IM ZUSAMMENHANG MIT DER SOFTWARE ODER DER VERWENDUNG ODER ANDEREN HANDLUNGEN MIT DER

SOFTWARE.

### Kontaktieren Sie uns

Bitte senden Sie eine E-Mail an lishifenging@outlook.com.