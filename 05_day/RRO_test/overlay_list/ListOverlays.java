import android.content.om.IOverlayManager;
import android.content.om.OverlayInfo;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.os.UserHandle;
import android.util.Log;

import java.util.List;

public class ListOverlays {

    private static final String TAG = "ListOverlays";

    public static void main(String[] args) {
        /* 1. 결정할 타깃 패키지 (인자 없으면 SystemUI) */
        String targetPkg = (args.length > 0 && args[0] != null && !args[0].isEmpty())
                ? args[0]
                : "com.android.systemui";

        /* 2. OverlayManager 서비스 프록시 얻기 */
        IOverlayManager om = IOverlayManager.Stub.asInterface(
                ServiceManager.getService("overlay"));
        if (om == null) {
            Log.e(TAG, "OverlayManager service not found!");
            return;
        }

        try {
            /* 3. 오버레이 정보 가져오기 */
            List<OverlayInfo> overlays =
                    om.getOverlayInfosForTarget(targetPkg, UserHandle.myUserId());

            /* 4. 출력 */
            System.out.println("Overlay list for target \"" + targetPkg + "\"");
            System.out.println("----------------------------------------------");
            for (OverlayInfo info : overlays) {
                System.out.printf("%-50s : %s%n",
                        info.packageName,
                        info.isEnabled() ? "ENABLED" : "disabled");
            }
        } catch (RemoteException e) {
            // Binder IPC 오류는 시스템 서버 예외이므로 런타임으로 래핑
            throw new RuntimeException("Binder call failed", e);
        }
    }
}

