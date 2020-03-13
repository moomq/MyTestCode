
#!/usr/bin/python

#-*- coding:utf-8 -*-

#Filename:new_tax_2019_wages.py

#python V3.4.3

'''
累计预扣预缴应纳税所得额=累计收入-累计免税收入-累计减除费用-累计专项扣除-累计专项附加扣除-累计依法确定的其他扣除

本期应预扣预缴税额=（累计预扣预缴应纳税所得额×预扣率-速算扣除数)-累计减免税额-累计已预扣预缴税额

其中：累计减除费用，按照个税起征点5000元/月乘以纳税人当年截至本月在本单位的任职受雇月份数计算。

'''

 

def main():

    #每月工资总额

    wages=[]

    #起征点

    BASIC_WAGES=5000

    #社保、公积金、商业保险等缴纳总额

    social_security=[]

    #个人所得税专项附加扣除总额：=子女教育+继续教育+大病医疗+住房贷款利息+住房租金+赡养老人

    s_income_tax=3500

    #其他扣除项总额

    others_deduction=0

    #已预扣预缴税额

    tax_paid_list=[]

    #税后工资清单

    wages_list=[]

    #个人所得税预扣率表

    tax_rate_t={0:[0,36000,0.03,0],

                1:[36000,144000,0.1,2520],

                2:[144000,300000,0.2,16920],

                3:[300000,420000,0.25,31920],

                4:[420000,660000,0.3,52920],

                5:[660000,960000,0.35,85920],

                6:[960000,0.45,181920]

                }

    wages_tmp=int(input('请输入每月工资金额：'))
    social_security_tmp=float(input('请输入社保公积金缴纳金额：'))

    for y_months in range(12):

         #wages_tmp=    #int(input('请输入工资金额：'))

        wages.append(wages_tmp)

        # social_security_tmp=   #float(input('请输入社保公积金缴纳金额:'))

        social_security.append(social_security_tmp)

 
    
        # 累计预扣预缴应纳税所得额

        grand_total_taxable_income = sum(wages) - BASIC_WAGES * len(wages) - sum(social_security) - s_income_tax * len(wages) - others_deduction * len(wages)
 

        for i in range(len(tax_rate_t)):

            if grand_total_taxable_income>tax_rate_t[i][0] and grand_total_taxable_income<=tax_rate_t[i][1]:

                #预扣率

                pre_rate=tax_rate_t[i][2]

                #速算扣除数

                quick_deduction=tax_rate_t[i][3]

                #本期应预扣预缴税额:

                tax_amount_payable=grand_total_taxable_income*pre_rate-quick_deduction-sum(tax_paid_list)

                tax_paid_list.append(round(tax_amount_payable,2))

                wages_taxed=wages_tmp-social_security_tmp-others_deduction-tax_amount_payable

                wages_list.append(round(wages_taxed,2))

                break

            elif i==6 and grand_total_taxable_income>tax_rate_t[i][0]:

                #预扣率

                pre_rate=tax_rate_t[i][1]

                #速算扣除数

                quick_deduction=tax_rate_t[i][2]

                #本期应预扣预缴税额:

                tax_amount_payable=grand_total_taxable_income*pre_rate-quick_deduction-sum(tax_paid_list)

                tax_paid_list.append(round(tax_amount_payable,2))

                wages_taxed=wages_tmp-social_security_tmp-others_deduction-tax_amount_payable

                wages_list.append(round(wages_taxed,2))

                break

 

    print('每月纳税额清单：',tax_paid_list)

    print('每月税后工资：',wages_list)

    print('纳税总额：{}，税后工资总额：{},社保公积金：{},其他扣除项总额：{}'.format(round(sum(tax_paid_list),2),round(sum(wages_list),2),round(sum(social_security),2),others_deduction*(y_months+1)))

 

if __name__=='__main__':

    main()

