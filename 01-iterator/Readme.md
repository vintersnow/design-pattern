# Iterator

データを順番にアクセスするための方法を提供するパターン。
データコンテナに依らず同じ実装を使いたいので、データ構造と走査方法を別にしている。
ようは以下のようコードを動かしたい

```
for a in hoge {
  a is an element of hoge
}
```
