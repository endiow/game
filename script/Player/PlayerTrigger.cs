using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class PlayerTrigger : MonoBehaviour
{
    public GameObject PlayerObj;
    private void OnTriggerStay(Collider other)
    {
        if (other.gameObject.tag == "Enemy") 
        {
            PlayerObj.GetComponent<PlayerAttack>().AttackTrigger = true;
            PlayerObj.GetComponent<PlayerAttack>().EnemyObjTemp = other.gameObject;
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == "Enemy")
        {
            PlayerObj.GetComponent<PlayerAttack>().AttackTrigger = false;
        }
    }
}
