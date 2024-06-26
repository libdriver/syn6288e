[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SYN6288E

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/syn6288e/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SYN6288E中国語音声合成チップは、2010年初頭にBeijing Yuyintianxia Technology Co.、Ltd.によって発売された、より高いコストパフォーマンスとより自然な効果を備えたミドルおよびハイエンドの音声合成チップです。SYN6288Eは、非同期シリアルポートを介して合成されるテキストを受信します。 テキスト読み上げ（TTS）変換を実現します。 最新のSYN6288E音声合成チップは、OSYNO6188の優れた機能を継承しています。最小のLQFP32Lチップパッケージ、シンプルなハードウェアインターフェイス、および高コストパフォーマンス。 さらに、SYN6288Eテキスト認識はよりインテリジェントになり、音声合成はより自然になり、音声合成効果とインテリジェント認識効果が大幅に向上します。 ハイエンドアプリケーション向けの音声合成チップです。

LibDriver SYN6288Eは、LibDriverによって起動されたSYN6288Eの全機能ドライバーであり、テキスト合成、音楽合成、アラーム音合成などの機能を提供します。 LibDriverはMISRAに準拠しています。

### 目次

  - [説明](#説明)
  - [インストール](#インストール)
  - [使用](#使用)
    - [example basic](#example-basic)
    - [example advance](#example-advance)
  - [ドキュメント](#ドキュメント)
  - [貢献](#貢献)
  - [著作権](#著作権)
  - [連絡して](#連絡して)

### 説明

/ srcディレクトリには、LibDriver SYN6288E のソースファイルが含まれています。

/ interfaceディレクトリには、LibDriver SYN6288E 用のプラットフォームに依存しないUARTバステンプレートが含まれています。

/ testディレクトリには、チップの必要な機能を簡単にテストできるLibDriver SYN6288E ドライバーテストプログラムが含まれています。

/ exampleディレクトリには、LibDriver SYN6288E プログラミング例が含まれています。

/ docディレクトリには、LibDriver SYN6288E オフラインドキュメントが含まれています。

/ datasheetディレクトリには、SYN6288E データシートが含まれています。

/ projectディレクトリには、一般的に使用されるLinuxおよびマイクロコントローラー開発ボードのプロジェクトサンプルが含まれています。 すべてのプロジェクトは、デバッグ方法としてシェルスクリプトを使用しています。詳細については、各プロジェクトのREADME.mdを参照してください。

/ misraはLibDriver misraコードスキャン結果を含む。

### インストール

/ interfaceディレクトリにあるプラットフォームに依存しないUARTバステンプレートを参照して、指定したプラットフォームのUARTバスドライバを完成させます。

/src ディレクトリ、プラットフォームのインターフェイス ドライバー、および独自のドライバーをプロジェクトに追加します。デフォルトのサンプル ドライバーを使用する場合は、/example ディレクトリをプロジェクトに追加します。

### 使用

/example ディレクトリ内のサンプルを参照して、独自のドライバーを完成させることができます。 デフォルトのプログラミング例を使用したい場合の使用方法は次のとおりです。

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

### ドキュメント

オンラインドキュメント: [https://www.libdriver.com/docs/syn6288e/index.html](https://www.libdriver.com/docs/syn6288e/index.html)。

オフラインドキュメント: /doc/html/index.html。

### 貢献

CONTRIBUTING.mdを参照してください。

### 著作権

著作権（c）2015-今 LibDriver 全著作権所有

MITライセンス（MIT）

このソフトウェアおよび関連するドキュメントファイル（「ソフトウェア」）のコピーを取得した人は、無制限の使用、複製、変更、組み込み、公開、配布、サブライセンスを含む、ソフトウェアを処分する権利を制限なく付与されます。ソフトウェアのライセンスおよび/またはコピーの販売、および上記のようにソフトウェアが配布された人の権利のサブライセンスは、次の条件に従うものとします。

上記の著作権表示およびこの許可通知は、このソフトウェアのすべてのコピーまたは実体に含まれるものとします。

このソフトウェアは「現状有姿」で提供され、商品性、特定目的への適合性、および非侵害の保証を含むがこれらに限定されない、明示または黙示を問わず、いかなる種類の保証もありません。 いかなる場合も、作者または著作権所有者は、契約、不法行為、またはその他の方法で、本ソフトウェアおよび本ソフトウェアの使用またはその他の廃棄に起因または関連して、請求、損害、またはその他の責任を負わないものとします。

### 連絡して

お問い合わせくださいlishifenging@outlook.com。