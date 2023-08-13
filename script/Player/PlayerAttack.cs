using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerAttack : MonoBehaviour
{
    public bool AttackTrigger;
    public GameObject EnemyObjTemp;
    private void Update()
    {
        if (Input.GetMouseButtonDown(0)) //Êó±ê×ó¼üµã»÷¹¥»÷
        {
            if (AttackTrigger == true) 
            {
                EnemyObjTemp.transform.parent.gameObject.GetComponent<Enemy>().EnemyInfo.EnemyHp -= 10;
            }
        }
    }
}
