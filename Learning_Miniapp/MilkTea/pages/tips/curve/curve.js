// pages/tips/curve/curve.js
Page({
  data: {
    titleCur: '雷诺矫正曲线📈',
    text: '&emsp;&emsp;燃烧热的测定有多种方法，其中<b>氧弹式热量计</b>是最常用的一种。实验的关键就是样品燃烧后热量计温度升高值(温差ΔT)的测量。由于热量计不可能做到100%的完全绝热，另外由于内部搅拌等因素也会带来热效应，因此需要对温差测量值进行校正。因此通常采用<b>雷诺温度作图法</b>进行校正。\n&emsp;&emsp;与手工坐标纸作图相比，Origin直接绘制雷诺温度校正图法精度高、误差小，简便快速。与计算机多段线性拟合雷诺图法相比，<b>Origin直接绘图法</b>直观且同样精度高、误差小，且更简便。以下为实验组同学绘图数据：(部分)\n',
    brandList: [
      {
        brand: '一点点',
        index: '0'
      }, {
        brand: '书亦烧仙草',
        index: '1'
      }, {
        brand: '厝内小眷村',
        index: '2'
      }, {
        brand: '茶百道',
        index: '3'
      }, {
        brand: 'CoCo都可',
        index: '4'
      }]
  },

  goToItem(e) {
    console.log(e.currentTarget.dataset.index)
    console.log(e.currentTarget.dataset.brand)

    wx.navigateTo({
      url: '../item/item?index=' + e.currentTarget.dataset.index +
        '&brand=' + JSON.stringify(e.currentTarget.dataset.brand) +
        '&title=""'
    })
  },

})