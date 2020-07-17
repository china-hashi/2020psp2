# 課題6 レポート

bb35319032 橋本千夏

## 課題

[sample/heights.csv]は標本全体のデータをまとめたものである．
今回の標本14人では，男性8人，女性6人であるが，同年代の工学部学生全体でも男性のほうが多いのだろうか．男性の割合<img src="/k06/tex/89f2e0d2d24bcf44db73aab8fc03252c.svg?invert_in_darkmode&sanitize=true" align=middle width=7.87295519999999pt height=14.15524440000002pt/>の推定範囲を求めよ．

[母比率の信頼区間][1]

[1]:../Reference/PopulationRatio.md

## ソースコードの説明

l.20: データファイル名を入力させ，fnameに格納

l.21: 入力させた文字列の最後にエンターキーが入っているので，fnameの文字列の最後をヌル文字'\0'に置換

l.24: fnameで指定したファイルの先頭アドレスをファイルポインタ fp に読み込む

l.25: もしfpがNULLだったときは，ファイルを開けなかったので，即座にプログラム終了

l.31: ファイルを1行ずつbufに読み込む．もし読み込み成功する限り以下を繰り返す

l.32: bufからscanfで数値文字列を実数としてgenderに読み込む

l.33: もしgenderが1ならnum_maleに1を足す

l.34: もしgenderが2ならnum_femaleに1を足す

l.35: それ以外ならnum_unknownに1を足す

l.38: 上記の3つを足してnum_wholeに代入

l.41: num_maleを出力

l.42: num_femaleを出力

l.43: ファイル内の男性の割合を出力

l.50: 関数get_boundを実行

l.52: 男性の推定範囲を出力

l.59: 関数get_boundを定義

l.83 :関数chooseを定義

## 入出力結果

Population Male Ratio (estimated) : 0.466667--0.600000


## 修正履歴

