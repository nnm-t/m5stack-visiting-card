# M5Stack Visiting Card

M5Stack 用電子名刺です.

起動時に Wi-Fi 経由で[鉄道遅延情報のjson](https://rti-giken.jp/fhc/api/train_tetsudo/) から JSON を取得し, 遅延路線をスクロールする機能を付けました.

## 動作環境

M5Stack Gray で動作確認済み.

## 使い方

Arduino IDE に, 予め `ArduinoJson` ライブラリを組み込んで下さい.

アイコンと QR コードは, `icon_mode.h` のファイルパスと `qr_mode.h` の URL を適宜差し替えて下さい.
アイコン画像は `bmp` 形式で MicroSD カードに保存しておきます.

その他, 表示内容は `m5stack-visiting-card.ino` の文字列リテラルを書き換えて下さい.

和文フォントは, [M5Stackで好きなフォントを使う](https://watako-lab.com/2018/10/31/m5_font/) を参考にして, [M+フォント](https://mplus-fonts.osdn.jp/)を MicroSD カードから読み込むように設定しています.
