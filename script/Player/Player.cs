using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Player : MonoBehaviour
{
    public int PlayerHp;

    // Start is called before the first frame update
    void Start()//��ҳ�ʼ��
    {
        PlayerHp = 100;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.Escape)) 
        {
            SceneManager.LoadScene("DeathScene");
        }
        Death();
    }

    void Death()//��������
    {
        if (PlayerHp <= 0f)
        {
            Debug.Log("�������");
            SceneManager.LoadScene("DeathScene");
        }
    }
}
