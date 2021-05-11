# 機械雲計費RESTful API測試工具
#

該測試工具參考以下swagger
- http://vmx-backend.csac.idv.tw/swagger/index.html?file=doc/smart-machine-platform.yaml#/

app列表(查找appId與appName的對應)
- http://vmx-backend.csac.idv.tw:8080/#/app


提供四種計費方式的API測試:
- 按次收費
- 按時收費
- 按月收費
- 買斷制

## 按次收費
POST 
http://{IP}:{Port}/dw/metering/count/raw

Payload內容範例 (json格式)
```sh
{
  "deviceId": "E3B3D13ADAB443D64E800CA88B06FC8F",
  "appName": "iCAM",
  "appId": "8f14e45fceea167a5a36dedd4bea2543",
  "userId": "paul@itri.org.tw",
  "type": "count",
  "countName": "APInumber",
  "count": 100
}
```
> 注意: 上述的appId、appName、type是有對應關係的, `不能亂填`
> 如appName 'iCAM' 所對應的 appId為 '8f14e45fceea167a5a36dedd4bea2543',
> 且appName 'iCAM'當初登記的收費方式為 '按次收費'("type": "count"), 
> 詳細資訊都記錄在以下網址 'app列表'

app列表
- http://vmx-backend.csac.idv.tw:8080/#/app



## 按時收費
POST 
http://{IP}:{Port}/dw/metering/time/raw

Payload內容範例 (json格式)
```sh
{
  "deviceId": "E3B3D13ADAB443D64E800CA88B06FC8F",
  "appName": "Notepad",
  "appId": "notepadsampleapp",
  "userId": "paul@itri.org.tw",
  "type": "time",
  "time": 3600
}
```
> OPCUA這個app使用了3600秒
> appName, appId, type 綁定關係請看 'app列表' 網址



## 按月收費
POST 
http://{IP}:{Port}/dw/metering/subscription/raw

Payload內容範例 (json格式)
```sh
{
  "deviceId": "E3B3D13ADAB443D64E800CA88B06FC8F",
  "appName": "Metering Tool ( Test 20210424 )",
  "appId": "zjhQ114XT6nHVGLaZ0g87fG4DUfcZYV5",
  "userId": "paul@itri.org.tw",
  "type": "subscription",
  "year": 2021,
  "month": 5
}
```
> appName, appId, type 綁定關係請看 'app列表' 網址



## 買斷制
POST 
http://{IP}:{Port}/dw/metering/buyout/raw

Payload內容範例 (json格式)
```sh
{
  "deviceId": "E3B3D13ADAB443D64E800CA88B06FC8F",
  "appName": "OPCUA",
  "appId": "6512bd43d9caa6e02c990b0a82652dca",
  "userId": "paul@itri.org.tw",
  "type": "buyout"
}
```
> appName, appId, type 綁定關係請看 'app列表' 網址