using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class StartButtonUI : MonoBehaviour
{
    public void StartButton()
    {
        Debug.Log("��ʼ��Ϸ");
        SceneManager.LoadScene("MainScene");
    }

    public void ExitButton()
    {
        Debug.Log("�˳���Ϸ");
        Application.Quit();
    }

    public void RegameButton()
    {
        Debug.Log("������Ϸ");
        SceneManager.LoadScene("MainScene");
    }

    public void BackButton()
    {
        Debug.Log("�������˵�");
        SceneManager.LoadScene("StartScene");
    }
}
