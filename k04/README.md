# 課題4 レポート

bb35319032 橋本千夏

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明

l.5: 構造体を定義

l.25: データファイル名を入力させ，fnameに格納

l.26: 入力させた文字列の最後にエンターキーが入っているので，fnameの文字列の最後をヌル文字'\0'に置換

l.28: fnameで指定したファイルの先頭アドレスをファイルポインタ fp に読み込む

l.29: もしfpがNULLだったときは，ファイルを開けなかったので，即座にプログラム終了

l.35: ファイルを1行ずつbufに読み込む．もし読み込み成功する限り以下を繰り返す

l.36: bufからscanfで数値文字列を実数としてgenderとheightに読み込む

l.37: data.genderにgenderを格納

l.38: data.heightにheightを格納

l.43: データファイル名を入力させ，fnameに格納

l.44: 入力させた文字列の最後にエンターキーが入っているので，fnameの文字列の最後をヌル文字'\0'に置換

l.46: fnameで指定したファイルの先頭アドレスをファイルポインタ fp に読み込む

l.47: もしfpがNULLだったときは，ファイルを開けなかったので，即座にプログラム終了

l.53: ファイルを1行ずつbufに読み込む．もし読み込み成功する限り以下を繰り返す

l.54: bufからscanfで数値文字列を実数としてIDに読み込む

l.55: data.IDにIDを格納

l.60: 調べたいIDをscanfでiIdに読み込む

l.62: iが15未満まで以下を繰り返す

l.63: もしiIDが構造体に格納されているIDと同じなら以下の処理をする

l.64: もしgenderが1なら以下を出力

l.68: もしgenderが2なら以下を出力

l.73: そのときのiの値をnに格納

l.76: もしnが0,すなわち調べたいIDがなかった場合は以下を出力


## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴
[comment0706宮下]

課題提出お疲れさまでした！修正点はありません。k04は完了です。

[comment #20200707 sonoda]
- 課題4の完了を確認しました．（薗田）
