using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Script : MonoBehaviour
{
    // Start is called before the first frame update
    public float[] TimePoints;
    public Vector3[] EnemyPositions;

    public GameObject EnemyObj;
    public float GameTime;

    public bool flag;


    private void Start()//��������
    {
        TimePoints = new float[3];
        flag = false;
        TimePoints[0] = 60f;
        TimePoints[1] = 120f;
        TimePoints[2] = 180f;

        //EnemyInfo enemyInfo;

        //EnemyObj = (GameObject)Resources.Load("Enemy");
    }
    private void Update()
    {
        GameTime += Time.deltaTime;
        EnemyTime();
    }
    void EnemyTime()//��������
    {
        if (GameTime < TimePoints[0] && flag==false)
        {
            EnemyGererate(7);
            flag = true;
        }
        else if (GameTime > TimePoints[0] && GameTime < TimePoints[1] && flag==true)
        {
            EnemyGererate(13);
            flag = false;
        }
        else if (GameTime > TimePoints[1] && GameTime < TimePoints[2] && flag == false)
        {
            EnemyGererate(18);
            flag = true;
        }
    }

    void EnemyGererate(int number)//���ĸ��������������
    {
        for(int i=0;i<number;i++)
        {
            int temp = Random.Range(0, 4);//ȡ0 1 2 3 �ĸ�����һ��
            Instantiate(EnemyObj, EnemyPositions[temp], this.gameObject.transform.rotation);
        }
        
    }
    
}
